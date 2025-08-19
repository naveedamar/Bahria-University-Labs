/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab1;

/**
 *
 * @author navee
 */
public class task4 {

    public void display_Task4() {
        int[] numbers = {123, 12, 312, 1341, 2342, 1424, 2, 23, 421, 345, 123, 102};
        int search = 12;

        for (int i = 0; i < numbers.length; i++) {
            if (search == numbers[i]) {
                System.out.println("Number " + search + " found at array index " + i);
            }else if(i == numbers.length){
                System.out.println("Number not in array.");
            }
        }
    }

}
