/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */
package com.mycompany.lab9;

import java.util.*;

/**
 *
 * @author navee
 */
public class Lab9 {

    public static void main(String[] args) {
        
        //for shapes abstract
//        Shape[] shapes = {
//            new Circle(5),
//            new Rectangle(4, 6),
//            new Triangle(3, 7)
//        };
//
//        for (Shape shape : shapes) {
//            shape.DisplayDetails();
//            shape.CalculateArea();
//            System.out.println();
//        }

        //for vehicle abstract
        List<Vehicle> vehicles = new ArrayList<>();
        Car car1 = new Car();
        Motorcycle motor1 = new Motorcycle();
        Truck truck1 = new Truck();

        vehicles.add(car1);
        vehicles.add(motor1);
        vehicles.add(truck1);

        System.out.println("Vehicles: \n");
        for (Vehicle v1 : vehicles) {
            v1.DisplayVehicleType();
            v1.StartEngine();
            v1.StopEngine();
            System.out.println("");
        }

    }
}
