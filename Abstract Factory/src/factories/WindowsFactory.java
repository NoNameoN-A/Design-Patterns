package factories;

import Bottoni.*;
import checkboxes.*;

public class WindowsFactory implements GUIFactory {

    @Override
    public Button createButton() {
        return new BottoneWindows();
    }

    @Override
    public Checkbox createCheckbox() {
        return new CheckboxWindows();
    }
}