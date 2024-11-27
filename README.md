
# Auto plant 

A simple auto-watering script designed to help take care of your plants by automatically monitoring and watering them based on moisture levels.

## Features

- **Moisture Sensing**: The system reads the moisture levels of two plants using analog or digital sensors.
- **Water Pump Control**: The system activates water pumps to water the plants when moisture levels are low.
- **Water Reservoir Check**: Ensures there is enough water in the reservoir before activating the pumps.
- **Power Efficiency**: Utilizes sleep modes and power management techniques to minimize power consumption.

## Requirement 
- 1x Arduino
- 2x Moisture Sensors (Analog or Digital)
- 2x Water Pumps
- 2x Water Hoses (for connecting water pumps to plants)
- 1x Water Level Sensor
- 1x Power Supply (Battery or mobile adaptor)

## Setup 

1. **Set up your circuit**:  
   Connect your Arduino to the moisture sensors, water pumps, and water level sensor. Use the water hoses to connect the pumps to the plants.

2. **Download the script**:  
   Download the script from the releases section.

3. **Change the pin numbers**:  
   Open the script and modify the pin numbers to match the pins you're using on your Arduino.

4. **Upload the script to your Arduino**:  
   Upload the code to your Arduino using the Arduino IDE.

5. **Test & Enjoy :)**

   
## Customization

If you have more plants or different types of plants, you can modify the functions to suit your needs:

- Change the function names like `check_peperomia_moisture()` and `check_pothos_moisture()` to the names or types of the plants connected to the moisture sensors. For example, use `check_[your_plant_name_or_type]_moisture()` (e.g., `check_cactus_moisture()`).
  
- Adjust the water pump control functions like `turn_on_pothos_water_pumps()` and `turn_on_peperomia_water_pump()` to match the names or types of plants connected to the water pumps. For example, use `turn_on_[your_plant_name_or_type]_water_pumps()` (e.g., `turn_on_cactus_water_pumps()`).
  
> [!IMPORTANT]
> If you have more than two plants, you can duplicate the `check_pothos_moisture()` and `turn_on_peperomia_water_pump()` functions, changing the pins in the copied functions to match your additional plant setup.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
