//Created by Tim Buranicz

package program_1;

public class White_Mage extends Job{
    /**
     * Prints out info from class obj
     */
    @Override
    void printInfo(){
        System.out.println("Class: White Mage");
        System.out.println("Name: "+name);
        System.out.println("Name: "+ level);
    }
    /**
     * Constructor
     */
    White_Mage(String name, int level){
        super.name = name;
        super.level = level;
    }
}
