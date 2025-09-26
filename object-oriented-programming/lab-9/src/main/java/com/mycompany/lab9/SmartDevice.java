/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.lab9;

/**
 *
 * @author navee
 */
public class SmartDevice implements iMusicPlayer, iVideoPlayer{
    
    public void playMusic(){
        System.out.println("Playing Music");
    }
    
    public void playVideo(){
        System.out.println("Playing Video");
    }
}
