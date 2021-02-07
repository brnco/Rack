#pragma once
#include <ui/common.hpp>
#include <widget/OpaqueWidget.hpp>
#include <Quantity.hpp>
#include <context.hpp>


namespace rack {
namespace ui {


struct RadioButton : widget::OpaqueWidget {
	/** Not owned. */
	Quantity* quantity = NULL;

	RadioButton();
	void draw(const DrawArgs& args) override;
	void onDragDrop(const DragDropEvent& e) override;
};


} // namespace ui
} // namespace rack
