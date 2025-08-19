/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab7;

/**
 *
 * @author navee
 */
public class VIPLuxurySuite extends LuxurySuite {

    boolean personalButlerService;

    public VIPLuxurySuite() {
        super(personalButlerService = true);
    }

    public double calculateBookingCost(int numberOfNights, float premiumServices) {
        return ((numberOfNights * super.getPricePerNight()) + premiumServices);
    }
}
