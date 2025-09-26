/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab9;

/**
 *
 * @author navee
 */
public abstract class Vehicle {

    public abstract String VehicleType();

    public abstract void StartEngine();

    public abstract void StopEngine();

    public void DisplayVehicleType() {
        System.out.println("Type of Vehicle is " + VehicleType());
    }

}
