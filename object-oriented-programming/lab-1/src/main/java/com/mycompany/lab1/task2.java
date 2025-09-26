/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab1;

import java.util.Scanner;

/**
 *
 * @author navee
 */
public class task2 {
    public void display_Task2() {
        double num1, num2, result;
        char operator;
        
        Scanner ch = new Scanner(System.in);
        
        System.out.println("Enter First Num: ");
        num1 = ch.nextDouble();
        
        System.out.println("Enter Operator(/, *, +, -): ");
        operator = ch.next().charAt(0);
        
        System.out.println("Enter Second Num: ");
        num2 = ch.nextDouble();
        
        switch(operator)
        {
            case '/':
                result = num1 / num2;
                System.out.println(num1 + " / " + num2 + " = " + result);
                break;
            case '*':
                result = num1 * num2;
                System.out.println(num1 + " * " + num2 + " = " + result);
                break;
            case '+':
                result = num1 + num2;
                System.out.println(num1 + " + " + num2 + " = " + result);
                break;
            case '-':
                result = num1 - num2;
                System.out.println(num1 + " - " + num2 + " = " + result);
                break;  
            default:
                System.out.println("Invalid operator!");
        }
        ch.close();
    }
}