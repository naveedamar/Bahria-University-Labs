/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab7;

/**
 *
 * @author navee
 */
sealed class Vehicle permits Car, Bike{
    
    
    public Vehicle(){
        
    }
    
    public void start(){
        System.out.println("Start");
    }
    
    public void displayinfo(){
        System.out.println("Nothing to display");
    }
    
    public void displayinfo(String Data){
        System.out.println(Data + " to display");
    }
}
