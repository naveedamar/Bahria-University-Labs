/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab7;

/**
 *
 * @author navee
 */
public class StandardRoom extends Room{
    
    boolean hasTV;
    public StandardRoom(){
        super(7, 50, "Standard", true);
        hasTV = true;
    }
    
    public double calculateBookingCost(int numberOfNights) {
        return (numberOfNights * super.getPricePerNight() );
    }
}
