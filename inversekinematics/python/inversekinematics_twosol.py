import math

def inverse_kinematics(x, y, L1, L2):
    # Calcular d
    d = (x**2 + y**2 - L1**2 - L2**2) / (2 * L1 * L2)
    
    # Verificar si d está dentro del rango válido (-1 <= d <= 1)
    if d < -1 or d > 1:
        raise ValueError("La posición (x, y) no es alcanzable con las longitudes dadas.")

    # Calcular θ2 para ambas soluciones (codo arriba y codo abajo)
    theta2_1 = math.atan2(math.sqrt(1 - d**2), d)  # Solución "codo arriba"
    theta2_2 = math.atan2(-math.sqrt(1 - d**2), d)  # Solución "codo abajo"
    
    # Calcular θ1 para la solución "codo arriba"
    k1_1 = L1 + L2 * math.cos(theta2_1)
    k2_1 = L2 * math.sin(theta2_1)
    theta1_1 = math.atan2(y, x) - math.atan2(k2_1, k1_1)
    
    # Calcular θ1 para la solución "codo abajo"
    k1_2 = L1 + L2 * math.cos(theta2_2)
    k2_2 = L2 * math.sin(theta2_2)
    theta1_2 = math.atan2(y, x) - math.atan2(k2_2, k1_2)
    
    # Convertir los ángulos a grados para mejor interpretación
    theta1_1_deg = math.degrees(theta1_1)
    theta2_1_deg = math.degrees(theta2_1)
    theta1_2_deg = math.degrees(theta1_2)
    theta2_2_deg = math.degrees(theta2_2)
    
    return (theta1_1_deg, theta2_1_deg), (theta1_2_deg, theta2_2_deg)

# Ejemplo de uso
x = 3
y = 4
L1 = 3
L2 = 2

try:
    (theta1_1, theta2_1), (theta1_2, theta2_2) = inverse_kinematics(x, y, L1, L2)
    print(f"Solución 1 (codo arriba): θ1 = {theta1_1:.2f} grados, θ2 = {theta2_1:.2f} grados")
    print(f"Solución 2 (codo abajo): θ1 = {theta1_2:.2f} grados, θ2 = {theta2_2:.2f} grados")
except ValueError as e:
    print(e)
