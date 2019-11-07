import math

class Car:
    """
    Object represents a brand new car
    """

    def __init__(self, length, doors):
        """
        Car constructor
        """
        if (length < 7):
            raise ValueError('Car length musty be at least 7 characters')
        else:
            self.length = length

        if (doors < 1):
            raise ValueError('Car must have at least 1 door.')
        elif (doors*2 > length-2):
            raise ValueError(f'Too many doors for car of length {length}.')
        else:
            self.doors = doors
        
        self.body = Body(length, doors)
        self.chassis = Chassis(length)
    
    def display(self):
        print(self.body.component + self.chassis.component)


class Part():
    """
    Represents a car part
    """

    def __init__(self, length):
        self.length = length
        self.component = self.getComponent()

    def getComponent(self):
        raise NotImplementedError

class Body(Part):
    """
    Body of the car
    """

    def __init__(self, length, doors):
        self.doors = doors
        super().__init__(length)
        

    def getComponent(self):
        """
        Generate the Body component
        """
        return self.generate_first_layer() + self.generate_second_layer()

    def generate_first_layer(self):
        roof = ''.join(['_' for i in range(self.length-3)])
        return f' {roof} \n'

    def generate_second_layer(self):
        layer_total_spaces = self.length - 2*self.doors - 3
        spaces = ''.join([' ' for i in range(layer_total_spaces)])
        front_doors = ''.join('[]' for i in range(math.ceil(self.doors/2)))
        back_doors  = ''.join(['[]' for i in range(math.floor(self.doors/2))])

        return f'|{back_doors}{spaces}{front_doors}\\\n'
            


class Chassis(Part):
    """
    Chasis for the car
    """
    
    def getComponent(self):
        axle = '-o'
        num_axles = self.num_axles(self.length)
        num_spaces = self.length - num_axles*2 - 2
        front_axles = ''.join([axle for i in range(math.floor(num_axles / 2))])
        back_axles = ''.join([axle for i in range(math.ceil(num_axles / 2))])
        spaces = ''.join(['-' for i in range(num_spaces)])
        front_piece = '-\''

        return(f'{back_axles}{spaces}{front_axles}{front_piece}')

    def num_axles(self, l):
        return max(2, 3 + ((l - 12) // 2))



if __name__ == '__main__':

    car = Car(16, 5)
    car.display()

    print('\n\n')

    car = Car(9, 3)
    car.display()

    print('\n\n')

    car = Car(13, 1)
    car.display()