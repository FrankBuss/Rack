#include "ui/Slider.hpp"


namespace rack {
namespace ui {


static const float SENSITIVITY = 0.001f;


Slider::Slider() {
	box.size.y = BND_WIDGET_HEIGHT;
}

Slider::~Slider() {
	if (quantity)
		delete quantity;
}

void Slider::draw(const widget::DrawContext &ctx) {
	float progress = quantity ? quantity->getScaledValue() : 0.f;
	std::string text = quantity ? quantity->getString() : "";
	bndSlider(ctx.vg, 0.0, 0.0, box.size.x, box.size.y, BND_CORNER_NONE, state, progress, text.c_str(), NULL);
}

void Slider::onDragStart(const event::DragStart &e) {
	state = BND_ACTIVE;
	APP->window->cursorLock();
}

void Slider::onDragMove(const event::DragMove &e) {
	if (quantity) {
		quantity->moveScaledValue(SENSITIVITY * e.mouseDelta.x);
	}
}

void Slider::onDragEnd(const event::DragEnd &e) {
	state = BND_DEFAULT;
	APP->window->cursorUnlock();
}

void Slider::onButton(const event::Button &e) {
	if (e.action == GLFW_PRESS && e.button == GLFW_MOUSE_BUTTON_RIGHT) {
		if (quantity)
			quantity->reset();
	}
	e.consume(this);
}


} // namespace ui
} // namespace rack
