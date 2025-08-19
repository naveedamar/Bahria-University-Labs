/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab1;
import java.util.ArrayList;

/**
 *
 * @author navee
 */
public class task8 {

    public void display_Task8() {
        int[][] arr1 = {{1, 2, 3}, {1, 2, 3}};
        int[][] arr2 = {{1, 2, 3}, {4, 8, 6}};
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();

        for (int i = 0; i < arr1.length; i++) {
            result.add(new ArrayList<>()); 
            for (int j = 0; j < arr1[0].length; j++) {
                result.get(i).add(arr1[i][j] * arr2[i][j]);
            }
        }

        System.out.println("Result:");
        for (ArrayList<Integer> row : result) {
            for (int num : row) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }

}
