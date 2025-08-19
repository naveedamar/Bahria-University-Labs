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
public class Part_Time_Employee extends Employee {

    public Part_Time_Employee() {
        int number_of_hours;
        float wage;

        Scanner scan = new Scanner(System.in);

        System.out.println("Enter Number of hours worked: ");
        number_of_hours = scan.nextInt();

        System.out.println("Enter Wage: ");
        wage = scan.nextFloat();
    }
}
