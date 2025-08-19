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
public class Freelancer extends Part_Time_Employee {
    public Freelancer(){
        
        String Name, email;
        int cost;
        
        Scanner scan = new Scanner(System.in);
        
        System.out.println("Enter Freelancer\'s Name: ");
        Name = scan.nextLine();
        System.out.println("Enter Freelancer\'s Email: ");
        email = scan.nextLine();
        System.out.println("Enter Freelancer\'s cost: ");
        cost = scan.nextInt();
        
    }
    
}
