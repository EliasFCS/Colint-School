# Définition d'une classe
class Robot
  # Génère automatiquement les méthodes pour lire et modifier le nom
  attr_accessor :nom

  # Constructeur
  def initialize(nom)
    @nom = nom # Variable d'instance
  end

  # Méthode pour saluer
  def saluer(heure)
    if heure < 18
      puts "Bonjour ! Je m'appelle #{@nom}."
    else
      puts "Bonsoir ! Je m'appelle #{@nom}."
    end
  end
end

# Création d'un objet (instance de classe)
mon_robot = Robot.new("Robot")

# Appel de la méthode
mon_robot.saluer(14)

# Une boucle simple pour compter jusqu'à 3
puts "\nDécompte de sécurité :"
3.times do |i|
  puts "Index : #{i + 1}"
end

#CODE trouvé sur GOOGLE pour faire des tests dessus!!!