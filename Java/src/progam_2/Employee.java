/**
 * Program 2
 * Authors: Trevor Murphy, Tim Lewis, 
 * -Trevor and Tim L worked together on creating the program via live share so Tim L will not appear in the commit history for that part
 */

package progam_2;
import java.util.Scanner;
import java.util.ArrayList;


public class Employee {
    String firstName,lastName,middleInitial;
    int employeeID;
    double payRate;
    String startDate,terminationDate;

    // Used for ID generation
    int currentIDNumber=0;

    // Constructor
    public Employee(){

    }

    public Employee(String firstName, String lastName, String middleInitial, int employeeID, double payRate, String startDate, String terminationDate){
        this.firstName = firstName;
        this.lastName = lastName;
        this.middleInitial = middleInitial;
        this.employeeID = employeeID;
        this.payRate = payRate;
        this.startDate = startDate;
        this.terminationDate = terminationDate;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getMiddleInitial() {
        return middleInitial;
    }

    public void setMiddleInitial(String middleInitial) {
        this.middleInitial = middleInitial;
    }

    public int getEmployeeID() {
        return employeeID;
    }

    public void setEmployeeID(int employeeID) {
        this.employeeID = employeeID;
    }

    public double getPayRate() {
        return payRate;
    }

    public void setPayRate(double payRate) {
        this.payRate = payRate;
    }

    public String getStartDate() {
        return startDate;
    }

    public void setStartDate(String startDate) {
        this.startDate = startDate;
    }

    public String getTerminationDate() {
        return terminationDate;
    }

    public void setTerminationDate(String terminationDate) {
        this.terminationDate = terminationDate;
    }

    @Override
    public String toString() {
        return "Employee [firstName=" + firstName + ", lastName=" + lastName + ", middleInitial=" + middleInitial
                + ", employeeID=" + employeeID + ", payRate=" + payRate + ", startDate=" + startDate
                + ", terminationDate=" + terminationDate + "]";
    }

    public int generateEmployeeID(){
        currentIDNumber++;
        return currentIDNumber;
    }

    public Employee addEmployee(){
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter first name: ");
        String firstName = scan.nextLine();
        System.out.print("Enter last name: ");
        String lastName = scan.nextLine();
        System.out.print("Enter middle initial: ");
        String middleInitial = scan.nextLine();
        int employeeID = generateEmployeeID();
        System.out.print("Enter start date: ");
        String startDate = scan.nextLine();
        System.out.print("Enter termination date (NA if none set yet): ");
        String terminationDate = scan.nextLine();
        System.out.print("Enter pay rate ($x.xx): ");
        double payRate = scan.nextDouble();
        Employee emp = new Employee(firstName, lastName, middleInitial, employeeID, payRate, startDate, terminationDate);
        
        System.out.println("Employee successfully added.\nEmployee details: ");
        System.out.println(emp.toString());
        return emp;
    }

    public void terminateEmployee(ArrayList employeeArray){
        Scanner scan = new Scanner(System.in);
        Employee emp = employeeLookUp(employeeArray);
        if(emp == null){
            System.out.println("Employee not found.");
        }else{
            System.out.print("Enter termination date: ");
            String terminationDate = scan.nextLine();
            emp.setTerminationDate(terminationDate);
            System.out.println("Date set successfully.");
        }
    }

    public void changePay(ArrayList employeeArray){
        Scanner scan = new Scanner(System.in);
        Employee emp = employeeLookUp(employeeArray);
        double percent,changeInPay,payRate;
        if(emp == null){
            System.out.println("Employee not found.");
        }else{
            int flag = 0;

            while(flag != 1)
            {
                System.out.println("Select an option:\n 1: Increase/Decrease by percentage.\n 2: Edit by flat dollar amount.\n 3: Increase/Decrease flat dollar amount\n 0: Exit\n Choice: " ); 
                int x = scan.nextInt();
                switch(x){
                    case 0: flag = 1; 
                        break;
                    case 1:
                        System.out.print("Would you like to increase or decrease by percentage?\n 1: Increase.\n 2: Decrease. \n 0: Exit percentage menu.\n Choice: ");
                        x = scan.nextInt();
                        switch(x){
                            case 0:
                                break;
                            case 1:
                                System.out.print("Enter percent: ");
                                percent = scan.nextDouble();
                                changeInPay = emp.getPayRate()*(percent/100);
                                emp.setPayRate(emp.getPayRate()+changeInPay);
                                System.out.println("\nPayrate updated.");
                                break;
                            case 2:
                                System.out.print("Enter percent: ");
                                percent = scan.nextDouble();
                                changeInPay = emp.getPayRate()*(percent/100);
                                emp.setPayRate(emp.getPayRate()-changeInPay);
                                System.out.println("\nPayrate updated.");
                                break;
                            default:
                                break;
                        }
                        break;
                    case 2:
                        System.out.print("Enter new pay rate: ");
                        payRate = scan.nextDouble();
                        emp.setPayRate(payRate);
                        System.out.println("\nPayrate updated.");
                        break;
                    case 3:

                        System.out.print("Would you like to increase or decrease by dollar amount?\n 1: Increase.\n 2: Decrease.\n 0: Exit dollar amount menu.\n Choice: ");
                        x = scan.nextInt();
                        switch(x){
                            case 0:
                                break;
                            case 1:
                                System.out.print("Enter increase: ");
                                changeInPay = scan.nextDouble();
                                emp.setPayRate(emp.getPayRate()+changeInPay);
                                System.out.println("\nPayrate updated.");
                                break;
                            case 2:
                                System.out.print("Enter decrease: ");
                                changeInPay = scan.nextDouble();
                                emp.setPayRate(emp.getPayRate()-changeInPay);
                                System.out.println("\nPayrate updated.");
                                break;
                            default:
                                System.out.println("Invalid Input" );
                        }
                }
            }
        }
            
    }

    public void editEmployee(ArrayList employeeArray){
        Scanner scan = new Scanner(System.in);
        Employee emp = employeeLookUp(employeeArray);
        if(emp == null){
            System.out.println("Employee not found.");
        }else{
        int flag = 0;

        while(flag != 1)
        {
            System.out.print("Select an option\n 1: Edit first name.\n 2: Edit last name\n 3: Edit middle initial.\n 4: Edit start date.\n 5: Edit termination date.\n 0: Exit.\n Choice: " ); 
            int x = scan.nextInt();
            switch(x){
                case 0: 
                    flag = 1; 
                    break;
                case 1:
                    System.out.print("Enter New First name:");
                    String newFirstName = scan.next();
                    emp.setFirstName(newFirstName);
                    break;
                case 2:
                    System.out.print("Enter New Last name:");
                    String newLastName = scan.next();
                    emp.setLastName(newLastName);
                    break;
                case 3:
                    System.out.print("Enter New Middle Inittial:");
                    String newMiddleInitial = scan.next();
                    emp.setMiddleInitial(newMiddleInitial);
                    break;
                case 4:
                    System.out.print("Enter New Start Date: ");
                    String newStartDate = scan.next();
                    emp.setStartDate(newStartDate);
                    break;
                case 5:
                    System.out.print("Enter New Termination Date:");
                    String newTerminationDate = scan.next();
                    emp.setTerminationDate(newTerminationDate);
                    break;
                default:
                    System.out.println("Invald input" );
                }
            }
        }
    }

    public Employee employeeLookUp(ArrayList employeeArray){
        Scanner scan = new Scanner(System.in);
        System.out.print("Enter employee ID: ");
        int employeeID = scan.nextInt();
        for(int i=0;i<employeeArray.size();i++){
            Employee emp = ((Employee) employeeArray.get(i));
            if(emp.getEmployeeID() == employeeID){
                System.out.println(emp.toString());
                return emp;
            }
        }

        return null;
    }


}