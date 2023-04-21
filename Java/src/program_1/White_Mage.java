//Created by Tim Buranicz

package program_1;

public class White_Mage extends Job{
    /**
     * Prints out info from class obj
     */
    @Override
    public String toString(){
        String output = "Class: White Mage";
        output += super.toString();
        return output;
    }
    /**
     * Constructor
     */
    White_Mage(String name, int level){
        super.name = name;
        super.level = level;
    }
}
