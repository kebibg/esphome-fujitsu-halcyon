#pragma once

#include <functional>

#include <esphome/core/component.h>
#include <esphome/components/switch/switch.h>

namespace esphome::custom {

class CustomSwitch : public Component, public switch_::Switch {
    public:
        CustomSwitch(std::function<bool(bool)> func, bool restore_on_setup = false) : func(func), restore_on_setup_(restore_on_setup) {};

        void setup() override {
            if (!this->restore_on_setup_)
                return;

            auto initial_state = this->get_initial_state_with_restore_mode();
            if (initial_state.has_value())
                this->control(initial_state.value());
        }

        void write_state(bool state) override { this->publish_state(this->func(state) ? state : this->state); };

    private:
        CustomSwitch() {};
        std::function<bool(bool)> func;
        bool restore_on_setup_{false};
};

}
