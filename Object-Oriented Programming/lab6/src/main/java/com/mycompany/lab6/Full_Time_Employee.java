/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab6;

import java.util.Scanner;

/**
 *
 * @author navee
 */
public class Full_Time_Employee extends Employee {

    public int salary;

    public Full_Time_Employee() {
        super();
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter Salary: ");
        this.salary = scan.nextInt();

    }

}
