/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab9;

/**
 *
 * @author navee
 */
public class Car extends Vehicle {

    @Override
    public String VehicleType() {
        return "Car";
    }

    @Override
    public void StartEngine() {
        System.out.println("Engine Started!");
    }

    @Override
    public void StopEngine() {
        System.out.println("Engine Stopped!");
    }

}
