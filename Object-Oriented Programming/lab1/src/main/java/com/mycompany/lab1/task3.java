/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab1;
import java.util.ArrayList;
/**
 *
 * @author naveed
 */
public class task3 {

    public boolean isPrime(int num) {
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                return false; // not prime
            }
        }
        return true; // prime
    }

    public void display_Task3() {
        int min = 2, max = 20;
        ArrayList<Integer> prime = new ArrayList<>();

        for (int i = min; i < max; i++) {
            if ( isPrime(i) ){
                prime.add(i);
            }
        }

        for (int i = 0; i < prime.size(); i++) {
            System.out.println(prime.get(i));
        }
    }
}
