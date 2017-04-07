package com.aerojasm.airwarcontroller;

import android.content.Intent;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;

import android.view.MotionEvent;
import android.view.View;
import android.widget.TextView;

import android.widget.ImageButton;


public class MainActivity extends AppCompatActivity implements SensorEventListener {

    private Sensor sensorGiroscopio;
    private SensorManager sensorGiroscopioM;
    private TextView textoX, textoY, textoZ, textoFire, textoPower;
    private ImageButton fireButton, powerButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        /*
        Se instancia las entidades encargadas de manear el sensor asi como sus datos y la forma
        en que estos se actualizan.
         */

        sensorGiroscopioM = (SensorManager) getSystemService(SENSOR_SERVICE);

        sensorGiroscopio = sensorGiroscopioM.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);

        sensorGiroscopioM.registerListener(this, sensorGiroscopio, sensorGiroscopioM.SENSOR_DELAY_NORMAL);

        textoX = (TextView) findViewById(R.id.X);

        textoY = (TextView) findViewById(R.id.Y);

        textoZ = (TextView) findViewById(R.id.Z);

        textoFire = (TextView) findViewById(R.id.fireButton);

        textoPower = (TextView) findViewById(R.id.powerButton);

        fireButton = (ImageButton) findViewById(R.id.imageButton);

        powerButton = (ImageButton) findViewById(R.id.imageButton2);


    }
    /*
     El event es un array el cual tiene los 3 valores X, Y, Z en ese orden respectivo
    si se gira lo suficiente (>= -2, para la Derecha y <= 2, para izquierda) se indica
    que hay accion.
     */
    @Override
    public void onSensorChanged(SensorEvent event) {
        textoX.setText("X: " + event.values[0]);

        if (event.values[0] <= -2) {
            textoY.setText("DERECHA");
            textoZ.setText("Siga DER");

        } else if (event.values[0] >= 2) {
            textoY.setText("IZQUIERDA");
            textoZ.setText("Siga IZQ");

        } else {
            textoZ.setText("Detengase");

        }
    }

    @Override
    public void onAccuracyChanged(Sensor sensor, int accuracy) {
        // No se usa en este caso.
    }

    /*
     ANDRES ACUERDESE DE BORRAR ESTO SI NO HACE LA CONECCION
    */
    public void nextLayout(View view) {
        Intent intent = new Intent(getApplicationContext(), Controller.class);
        startActivity(intent);
    }

    public void fire(View view) {
        fireButton.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction()== MotionEvent.ACTION_DOWN){
                    textoFire.setText("DISPARANDO");
                }else if (event.getAction()== MotionEvent.ACTION_UP){
                    textoFire.setText("NO dispara");
                }
                return true;

            }
        });


    }

    public void power(View view){
        powerButton.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction()== MotionEvent.ACTION_DOWN){
                    textoPower.setText("Power Up Utilizado");
                }else if (event.getAction()== MotionEvent.ACTION_UP){
                    textoPower.setText("Power Up en Espera");
                }

                return true;
            }
        });


    }
}