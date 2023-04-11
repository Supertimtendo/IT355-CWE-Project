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
        catch (FileNotFoundException e){
            System.out.println(e);
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
