//Created by Tim Buranicz

package program_1;

/**
 * Abstract class for job types
 */
abstract class Job {
    String name;
    int level;

    @Override
    public String toString(){
        String output = "Name: " + name + "\n" + "Level: " + level + "\n";
        return output;
    }
}
