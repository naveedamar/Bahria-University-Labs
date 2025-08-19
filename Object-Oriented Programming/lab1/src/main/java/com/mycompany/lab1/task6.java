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
public class task6 {
    
    public void display_Task6(){
        int a, b;
        Scanner scan = new Scanner(System.in);
        
        System.out.print("Enter A: ");
        a = scan.nextInt();
        System.out.print("Enter B: ");
        b = scan.nextInt();
        
        if(a > b){
            if( a / 6 == b / 6 ){
                System.out.println(b);
            }else{
                System.out.println(a);
            }
        }else if(a < b){
            if( a / 6 == b / 6){
                System.out.println(a);
            }else{
                System.out.println(b);
            }
        }else{
            System.out.println("0");
        }
    }
}
