fn main() {
    
    let age:u8 = 18;


    // Version sans match.
    let retour = if age < 13 {
        "Enfant"
    } else if age >= 13 && age < 18 {
        "Adolescent"
    } else if age >= 18 {
        "Adulte"
    } else {
    "N/A"
    };
    println!("Version sans match: {}", retour);




    // Version avec match.
    let retour2 = match age {
        0..=12 => "Enfant",
        13..=17 => "Adolescent",
        18.. => "Adulte",
        _ => "N/A"
    };
     println!("Version avec match: {}", retour2);
}