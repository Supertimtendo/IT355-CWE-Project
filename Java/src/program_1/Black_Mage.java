//Created by Tim Buranicz

package program_1;

public class Black_Mage extends Job{

    /**
     * Prints out info from class obj
     */
    @Override
    void printInfo(){
        System.out.println("Class: Black Mage");
        System.out.println("Name: "+name);
        System.out.println("Name: "+ level);
    }
    /**
     * Constructor
     */
    Black_Mage(String name, int level){
        super.name = name;
        super.level = level;
    }
}