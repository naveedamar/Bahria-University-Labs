/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab9;

/**
 *
 * @author navee
 */
public class Circle extends Shape {

    float radius;

    public Circle(float raduis) {
        this.radius = raduis;
    }

    public String Name() {
        return "Circle";
    }

    public void CalculateArea() {
        double area = Math.PI * Math.sqrt(radius);
        System.out.println("Area of Circle: " + area);
    }
}
