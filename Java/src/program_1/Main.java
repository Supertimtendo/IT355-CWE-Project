//Created by Tim Buranicz and Tom Freier

package program_1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Main driver class, inputs a data file that contains 3 lines:
 * class type (char), name (String), level (int) in that order on separate lines
 */

// CWE-209: Using manual try-catch or throws helps to avoid sensitive info being
// revealed by
// the compiler, and staying aware of what info you print via errors is
// important

// CWE-248: This program ensures that any exception used is always caught,
// making sure that
// the system does not go into an unexpected state

// CWE-460: When an error is thrown, the system exits or is cleaned up to ensure
// that no
// unexpected behavior occurs. Additionally, no error is thrown within a deeply
// nested
// logic function

public class Main {
    public static void main(String[] args) {
        Main main = new Main();
        // File name input
        Scanner scan = new Scanner(System.in);
        System.out.print("Input a file name: ");
        String fileName = scan.nextLine();
        scan.close();

        File file = new File(fileName);
        ArrayList<String> a = main.fileRead(file);
        ArrayList<Job> jobs = main.addPeople(a);
        main.printPeople(jobs);
        
        Black_Mage bm = (Black_Mage) jobs.get(1);
        runUntrustedMethod(bm);

        

    }

    /**
     * File to read info from a file
     * 
     * @param fileName File name to get file from
     * @return Returns array of info
     */
    private ArrayList<String> fileRead(File file) {
        // Stores info in file
        ArrayList<String> info = new ArrayList<>();
        try (Scanner read = new Scanner(file);) {

            while (read.hasNextLine()) {
                String data = read.nextLine();
                info.add(data);
            }
        }
        // CWE-537: This statement avoids printing out sensitive information about the
        // file system
        // of the system, minimizing exposed information
        catch (FileNotFoundException e) {
            System.err.println("File not found");
            e.printStackTrace();
            System.exit(1);
        }
        return info;
    }

    /**
     * Adds people objects to the list of the corresponding type
     * 
     * @param info List of data
     */
    private ArrayList<Job> addPeople(ArrayList<String> info) {
        ArrayList<Job> objs = new ArrayList<Job>();

        for (int i = 0; i < info.size(); i += 3) {
            /**
             * Avoids CWE-484: Omitted Break Statement in Switch
             * All cases have a break so there is NO potential for any fall through from occuring
             * 
             */
            switch (info.get(i)) {
                case "b":
                    Black_Mage b = new Black_Mage(info.get(i + 1), Integer.parseInt(info.get(i + 2)));
                    objs.add(b);
                    break;
                case "w":
                    White_Mage w = new White_Mage(info.get(i + 1), Integer.parseInt(info.get(i + 2)));
                    objs.add(w);
                    break;
                default:
                    System.out.println("Not proper input");
                    break;
            }
        }
        return objs;
    }

    /**
     * Prints each person in the list using their toString method
     * @param info List of data to print
     */
    private void printPeople(ArrayList<Job> info) {
        for (int i = 0; i < info.size(); i++) {
            System.out.println(info.get(i));
        }
    }

    private static void runUntrustedMethod(Black_Mage job){
        System.out.println("Object before running unstrusted method");
        System.out.println(job);


        /**
         * Avoids CWE-374: Passing Mutable Objects to an Untrusted Method
         * By passing a clone of this mutable object any changes in the untrusted method will only effect the cloned version, not the original version.
         */
        System.out.println("\nRunning with a cloned object:");
        Untrusted.potentiallyDangerousMethod((Black_Mage) job.clone());
        System.out.println("Object after running unstrusted metod on cloned object:");
        System.out.println(job);

        /**
         * Example of CWE-374
         * Changes on the object also effect the version of the object in the main method.
         * These side effects can have unintended consequences and results especially if unexpected.
         */
        System.out.println("\nRunning WITHOUT a cloned object");
        Untrusted.potentiallyDangerousMethod(job);
        System.out.println("Object after running unstrusted metod on mutable object directly");
        System.out.println(job);
    }
}
