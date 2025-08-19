/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.lab6;

/**
 *
 * @author navee
 */
public class Lab6 {

    public static void main(String[] args) {
        Full_Time_Employee new_employee = new Full_Time_Employee();
        //new_employee.display();

        System.out.println("This is a full time employee with salary: $" + new_employee.salary);

        SavingsAccount s1 = new SavingsAccount();
        BusinessAccount b1 = new BusinessAccount();
        System.out.println("");

        Library L1 = new Library();
        //L1.MAX_BOOKS = 1000;
        System.out.println("");

        SeniorManager seniorONe = new SeniorManager();
        seniorONe.displayinfo("John", 1600);
        seniorONe.bonus = 10000;
        seniorONe.teamSize = 12;

    }
}
