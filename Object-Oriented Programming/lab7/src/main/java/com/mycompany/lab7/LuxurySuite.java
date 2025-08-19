/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab7;

/**
 *
 * @author navee
 */
public class LuxurySuite extends Room {

    boolean hasJacuzzi;

    public LuxurySuite() {
        super(11, 500, "Luxury Suit", true);
        hasJacuzzi = false;
    }

    public LuxurySuite(boolean personalButtler) {
        super(11, 1000, "VIP Luxury Suit", true);
        hasJacuzzi = true;
    }
    
    public double calculateBookingCost(int numberOfNights, float luxuryTax ) {
        return ( (numberOfNights * super.getPricePerNight()) + luxuryTax );
    }

}
