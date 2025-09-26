/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab1;

/**
 *
 * @author navee
 */
public class task5 {
    
    public void display_Task5(){
        String str = "Naveed";
        char[] strr = str.toCharArray();
        System.out.println("Original String: " + str);
        System.out.print("Reverse String: ");
        
        for(int i = str.length() - 1 ; i >= 0 ; i--){
            System.out.print(strr[i]);
        }
    }
    
}
