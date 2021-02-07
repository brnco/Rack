#pragma once
#include <ui/common.hpp>
#include <ui/Menu.hpp>
#include <ui/MenuEntry.hpp>
#include <context.hpp>


namespace rack {
namespace ui {


struct MenuItem : MenuEntry {
	std::string text;
	std::string rightText;
	bool disabled = false;
	bool active = false;

	void draw(const DrawArgs& args) override;
	void step() override;
	void onEnter(const EnterEvent& e) override;
	void onDragDrop(const DragDropEvent& e) override;
	void doAction();
	virtual Menu* createChildMenu() {
		return NULL;
	}
	void onAction(const ActionEvent& e) override;
};


} // namespace ui
} // namespace rack
