#pragma once
#include "app/common.hpp"
#include "widget/FramebufferWidget.hpp"
#include "widget/SVGWidget.hpp"
#include "app/Switch.hpp"


namespace rack {
namespace app {


/** A ParamWidget with multiple frames corresponding to its value */
struct SVGSwitch : Switch {
	widget::FramebufferWidget *fb;
	widget::SVGWidget *sw;
	std::vector<std::shared_ptr<SVG>> frames;

	SVGSwitch();
	/** Adds an SVG file to represent the next switch position */
	void addFrame(std::shared_ptr<SVG> svg);
	void onChange(const event::Change &e) override;
};


} // namespace app
} // namespace rack
