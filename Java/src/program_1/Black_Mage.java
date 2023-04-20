//Created by Tim Buranicz and Tom Freier

package program_1;

public class Black_Mage extends Job{
    private String[] sensitiveData = {"Super,","Sensitive","Stuff"};
    /**
     * Prints out info from class obj
     */
    @Override
    void printInfo(){
        System.out.println("Class: Black Mage");
        System.out.println("Name: "+name);
        System.out.println("Level: "+ level);
        System.out.print("Sensitive Data: ");
        for(String s:sensitiveData){
            System.out.print(s + " ");
        }
        System.out.println();
    }
    /**
     * Constructor
     */
    Black_Mage(String name, int level){
        super.name = name;
        super.level = level;
    }

    /**
     * Returns a copy of the sensitive data related to this objects
     * @return sensitiveData array
     */
    public String[] getSenesitiveData(){
        /**
         * Avoids CWE-495: Private Data Structure Returned From A Public Method
         * 
         * Returning a clone of the private data structure prevents any modifications on the returned object effecting the intenteded private object.
         */
        return sensitiveData.clone();
    }

    /**
     * Sets new sensitive data for a Black_Mage object
     * Avoids CWE-496 and CWE-374 by creating a cloned of the mutable parameter that in the public scope
     * @param newData
     */
    public void setSensitiveData(String[] newData){
        /**
         * Avoids CWE-496: Public Data Assigned to Private Array-Typed Field
         * 
         * By cloning this publically-mutable array, we ensure that this data cannot have future modifications in the public scope
         */
        this.sensitiveData = newData.clone();
    }

    /**
     * Sets new level for a Black_Mage object
     * @param newLvl
     */
    public void setLevel(int newLvl){
        this.level = newLvl;
    }
    /**
     * Sets new name for a Black_Mage object
     * @param newName New name for the object
     */
    public void setName(String newName){
        // String are immutable so CWE-374: Passing Mutable Objects to an Untrusted Method
        // Doesn't apply here since strings are immutable
        this.name = newName; 
    }
    @Override
    protected Object clone() {
        String clonedName = new String(this.name);
        Black_Mage clonedMage = new Black_Mage(clonedName, this.level);
        clonedMage.sensitiveData = this.sensitiveData.clone(); // cloning the array since it's a mutable object
        return clonedMage;
    }  
}