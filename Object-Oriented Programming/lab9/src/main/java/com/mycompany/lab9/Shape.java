/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab9;

/**
 *
 * @author navee
 */
abstract class Shape {

    public abstract String Name();

    public abstract void CalculateArea();

    public void DisplayDetails() {
        System.out.println("Name of shape is " + Name());
    }

}
