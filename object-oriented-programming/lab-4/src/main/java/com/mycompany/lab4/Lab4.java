/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.lab4;

/**
 *
 * @author navee
 */
public class Lab4 {

    public static void main(String[] args) {
        Person p1 = new Student();
        p1.displayInfo();
        System.out.println("ID: " + ((Student) p1).getStudent_id());

        Car v1 = new Car();

        Circle s1 = new Circle();
        s1.draw();

        Child g1 = new Child();
        g1.showGrandparent();
        g1.showParent();
        g1.showChild();
        
        Dog a1 = new Dog();
        a1.makeSound();

    }
}
