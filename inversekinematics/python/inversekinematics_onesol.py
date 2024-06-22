import math

def inverse_kinematics(x, y, l1, l2):
    # Calcular d
    distance = (x**2 + y**2 - l1**2 - l2**2) / (2 * l1 * l2)
    
    # Verificar si d está dentro del rango válido (-1 <= d <= 1)
    if distance < 29 or distance > 40:
        raise ValueError("La posición (x, y) no es alcanzable con las longitudes dadas.\ndistancia: ", distance)

    # Calcular θ2 usando arctan2 para tener en cuenta los cuadrantes correctos
    theta2 = math.atan2(math.sqrt(1 - distance**2), distance)  # Solución "codo arriba"
    
    # Calcular k1 y k2
    k1 = l1 + l2 * math.cos(theta2)
    k2 = l2 * math.sin(theta2)
    
    # Calcular θ1 usando arctan2 para tener en cuenta los cuadrantes correctos
    theta1 = math.atan2(y, x) - math.atan2(k2, k1)
    
    # Convertir los ángulos a grados para mejor interpretación
    theta1_deg = math.degrees(theta1)
    theta2_deg = math.degrees(theta2)
    
    return theta1_deg, theta2_deg

# Ejemplo de uso
L1 = 15
L2 = 25

while True:
    try:
        x = int(input("x: "))
        y = int(input("y: "))
        theta1, theta2 = inverse_kinematics(x, y, L1, L2)
        print(f"θ1: {theta1:.2f} grados")
        print(f"θ2: {theta2:.2f} grados")
    except ValueError as e:
        print(e)