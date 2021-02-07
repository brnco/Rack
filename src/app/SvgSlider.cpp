#include <app/SvgSlider.hpp>


namespace rack {
namespace app {


SvgSlider::SvgSlider() {
	fb = new widget::FramebufferWidget;
	addChild(fb);

	background = new widget::SvgWidget;
	fb->addChild(background);

	handle = new widget::SvgWidget;
	fb->addChild(handle);

	speed = 2.0;
}

void SvgSlider::setBackgroundSvg(std::shared_ptr<Svg> svg) {
	background->setSvg(svg);
	fb->box.size = background->box.size;
	box.size = background->box.size;
}

void SvgSlider::setHandleSvg(std::shared_ptr<Svg> svg) {
	handle->setSvg(svg);
	handle->box.pos = maxHandlePos;
	fb->dirty = true;
}

void SvgSlider::onChange(const ChangeEvent& e) {
	engine::ParamQuantity* pq = getParamQuantity();
	if (pq) {
		// Interpolate handle position
		float v = math::rescale(pq->getSmoothValue(), pq->getMinValue(), pq->getMaxValue(), 0.f, 1.f);
		handle->box.pos = math::Vec(
		                    math::rescale(v, 0.f, 1.f, minHandlePos.x, maxHandlePos.x),
		                    math::rescale(v, 0.f, 1.f, minHandlePos.y, maxHandlePos.y));
		fb->dirty = true;
	}
	ParamWidget::onChange(e);
}


} // namespace app
} // namespace rack
