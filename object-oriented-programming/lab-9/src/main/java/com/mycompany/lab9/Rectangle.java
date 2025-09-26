/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab9;

/**
 *
 * @author navee
 */
public class Rectangle extends Shape {

    float width, height;

    public Rectangle(float width, float height) {
        this.width = height;
        this.height = height;
    }

    public String Name() {
        return "Rectangle";
    }

    public void CalculateArea() {
        double area = width * height;
        System.out.println("Area of Rectangle: " + area);
    }
}
