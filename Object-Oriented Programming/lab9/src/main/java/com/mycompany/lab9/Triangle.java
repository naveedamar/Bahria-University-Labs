/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab9;

/**
 *
 * @author navee
 */
public class Triangle extends Shape {

    float base, height;

    public Triangle(float base, float height) {
        this.base = base;
        this.height = height;
    }

    public String Name() {
        return "Triangle";
    }

    @Override
    public void CalculateArea() {
        double area = 0.5 * base * height;
        System.out.println("Area of Triangle: " + area);
    }
}
