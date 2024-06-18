import math

def inverse_kinematics(x, y, L1, L2):
    # Calcular d
    d = (x**2 + y**2 - L1**2 - L2**2) / (2 * L1 * L2)
    
    # Verificar si d está dentro del rango válido (-1 <= d <= 1)
    if d < -1 or d > 1:
        raise ValueError("La posición (x, y) no es alcanzable con las longitudes dadas.")

    # Calcular θ2 usando arctan2 para tener en cuenta los cuadrantes correctos
    theta2 = math.atan2(math.sqrt(1 - d**2), d)  # Solución "codo arriba"
    
    # Calcular k1 y k2
    k1 = L1 + L2 * math.cos(theta2)
    k2 = L2 * math.sin(theta2)
    
    # Calcular θ1 usando arctan2 para tener en cuenta los cuadrantes correctos
    theta1 = math.atan2(y, x) - math.atan2(k2, k1)
    
    # Convertir los ángulos a grados para mejor interpretación
    theta1_deg = math.degrees(theta1)
    theta2_deg = math.degrees(theta2)
    
    return theta1_deg, theta2_deg

# Ejemplo de uso
x = 2
y = 3
L1 = 3
L2 = 2

try:
    theta1, theta2 = inverse_kinematics(x, y, L1, L2)
    print(f"θ1: {theta1:.2f} grados")
    print(f"θ2: {theta2:.2f} grados")
except ValueError as e:
    print(e)