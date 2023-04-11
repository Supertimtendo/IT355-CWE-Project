package program_1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Main main = new Main();
        //File name input
        Scanner scan = new Scanner(System.in);
        System.out.println("Input a file name");
        String fileName = scan.nextLine();
        main.fileRead(fileName);
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
}
