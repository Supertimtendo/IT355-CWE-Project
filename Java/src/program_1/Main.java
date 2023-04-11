//Created by Tim Buranicz

package program_1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Main driver class, inputs a data file that contains 3 lines:
 * class type (char), name (String), level (int) in that order on separate lines
 */

// CWE-209: Using manual try-catch or throws helps to avoid sensitive info being revealed by
// the compiler, and staying aware of what info you print via errors is important

// CWE-248: This program ensures that any exception used is always caught, making sure that
// the system does not go into an unexpected state

// CWE-460: When an error is thrown, the system exits or is cleaned up to ensure that no
// unexpected behavior occurs. Additionally, no error is thrown within a deeply nested
// logic function

public class Main {
    public static void main(String[] args){
        Main main = new Main();
        //File name input
        Scanner scan = new Scanner(System.in);
        System.out.println("Input a file name:");
        String fileName = scan.nextLine();
        ArrayList a = main.fileRead(fileName);
        a = main.addPeople(a);
        main.printPeople(a);
    }

    /**
     * File to read info from a file
     * @param fileName File name to get file from
     * @return Returns array of info
     */
    private ArrayList<String> fileRead(String fileName){
        //Stores info in file
        ArrayList<String> info = new ArrayList<>();
        try{
            File file = new File(fileName);
            Scanner read = new Scanner(file);
            while(read.hasNextLine()){
                String data = read.nextLine();
                info.add(data);
            }
        }
        // CWE-537: This statement avoids printing out sensitive information about the file system
        // of the system, minimizing exposed information
        catch (FileNotFoundException e){
            System.out.println("File not found");
            System.exit(1);
        }
        return info;
    }

    /**
     * Adds people objects to the list of the corresponding type
     * @param info List of data
     */
    //TODO: Does not iterate over more than 1 obj, FIX
    private ArrayList<Job> addPeople(ArrayList<String> info){
        ArrayList objs = new ArrayList();

        for(int i=0;i<info.size()/3;i+=3){
            switch(info.get(i)){
                case "b":
                    Black_Mage b = new Black_Mage(info.get(i+1), Integer.parseInt(info.get(i+2)));
                    objs.add(b);
                    break;
                case "w":
                    White_Mage w = new White_Mage(info.get(i+1), Integer.parseInt(info.get(i+2)));
                    objs.add(w);
                    break;
                default:
                    System.out.println("Not proper input");
                    break;
            }
        }
        return objs;
    }
    private void printPeople(ArrayList<Job> info){
        for(int i=0;i<info.size();i++){
            info.get(i).printInfo();
        }
    }
}
