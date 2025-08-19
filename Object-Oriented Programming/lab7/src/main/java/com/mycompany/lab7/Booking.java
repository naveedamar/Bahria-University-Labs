/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab7;

/**
 *
 * @author navee
 */
public class Booking {
    private Room room;
    
    private String checkInDate;
    private int numberOfNights;
    private String guestInfo;
    private double bookingCost;
    
    public Booking(Room room, String checkInDate, int numberOfNights, String guestName) {
        this.room = room;
        this.checkInDate = checkInDate;
        this.numberOfNights = numberOfNights;
        this.guestInfo = guestName;
        this.bookingCost = room.getPricePerNight() * numberOfNights;
    }
}

