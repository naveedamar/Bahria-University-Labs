/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab10;

/**
 *
 * @author navee
 */
public class Car implements IVehicle, IEngine, ISafetyFeatures {
    @Override
    public void CheckBrakes(){
        System.out.println("Brakes Checked!");
    }
    @Override
    public void ActivateAirbags(){
        System.out.println("Air Bags Activated! ");
    }
    @Override
    public void StartEngine() {
        System.out.println("The car engine is now running.");
    }
    @Override
    public void Drive() {
        System.out.println("The car is driving.");
    }
    @Override
    public void Park() {
        System.out.println("The car is parked.");
    }
    @Override
    public void StopEngine() {
        System.out.println("The car engine is now stopped.");
    }
}
