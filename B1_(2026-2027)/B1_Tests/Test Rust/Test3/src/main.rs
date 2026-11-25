fn main() {


    let mut nombre:u8 = 3;
    let nom = String::from("Elias");

    // Boucle while
    while nombre > 0 && nom == "Elias" {
        println!("{} restant.", nombre);
        nombre -= 1;
    }
    println!("Fin boucle while.");



    // Boucle for.
    for i in 0..=10 {
        println!("{}", nombre + i)
    }
    println!("Fin boucle for.");

    // Autre boucle for.
    for i in (0..=10).step_by(5) {  //Avance de 5 en 5.
        println!("{}", nombre + i)
    }
    println!("Fin autre boucle for.");
}
