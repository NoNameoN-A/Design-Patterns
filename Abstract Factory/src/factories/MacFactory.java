package factories;

import Bottoni.BottoneMac;
import Bottoni.Button;
import checkboxes.Checkbox;
import checkboxes.CheckboxMac;

public class MacFactory implements GUIFactory {

    @Override
    public Button createButton() {
        return new BottoneMac();
    }

    @Override
    public Checkbox createCheckbox() {
        return new CheckboxMac();
    }
}