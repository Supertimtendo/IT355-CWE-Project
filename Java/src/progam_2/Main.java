/**
 * Program 2
 * Authors: Trevor Murphy, Tim Lewis, Lucas Beebe
 * -Trevor and Tim L worked together on creating the program via live share so Tim L will not appear in the commit history for that part
 */

package progam_2;
import java.util.Scanner;
import javax.print.attribute.standard.MediaSize.NA;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
    
    int flag = 0;
    Employee emp = new Employee();
    ArrayList<Employee> employeeArray = new ArrayList<Employee>();

    Employee emp1 = new Employee("t", "t", "t", 0, 1, "1", "1");
    Employee emp2 = new Employee(",", ",", ",", 1, 1, "1", "1");
    // Employee emp3 = new Employee(";", ";", ";", 0, 1, "1", "1");
    // Employee emp4 = new Employee("m", "m", "m", 0, 1, "1", "1");

    employeeArray.add(emp1);
    employeeArray.add(emp2);
    // employeeArray.add(emp3);
    // employeeArray.add(emp4);

    try{
    /**
    * CWE-395: Use of NullPointerException Catch to Detect NULL Pointer Dereference
    *  The program check for NULL Pointer Dereference and does not use the try catch to handle them for them.
     */
    if(emp != null)
    {
    while(flag != 1)
    {
        Scanner scan = new Scanner(System.in);
        
        System.out.print("Welcome to the program\n 1: Add New Employee\n 2: Terminate Employee\n 3: Change pay\n 4: Change Employee Details \n 5: Employee look up \n 6: THGOTG \n 0: Exit\n Choice: " ); 
        int x = scan.nextInt();
        switch(x){
            case 0: flag = 1; 
                break;
            case 1:
                employeeArray.add(emp.addEmployee());
                System.out.println(employeeArray.get(employeeArray.size()-1));

                /**
                 * CWE-595: comparison of Object References Instead of Object Contents. The contents of objects should
                 * be compared instead of the references. In this case, I added an easter egg to the simulation where the 
                 * first name of type String obj is compared to a String obj literal by using .equals() instead of '=='
                 */
                Employee checkAdmin = employeeArray.get(employeeArray.size()-1);
                if(checkAdmin.firstName.equals("Admin123")){
                    System.out.println("This is an Easter Egg");
                }
                break;
            case 2:
                emp.terminateEmployee(employeeArray);
                break;
            case 3:
                emp.changePay(employeeArray);
                break;
            case 4:
                emp.editEmployee(employeeArray);
                break;
            case 5:
                emp.employeeLookUp(employeeArray);
                break;
            case 6:
                emp.PrintVaribles();
                break;
            default:
                System.out.println("\nInvald Input"); 
         }
    }
    }
    }catch(NullPointerException npe)
    {      
    }
    }
    
}
