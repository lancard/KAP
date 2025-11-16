const boundary_fix_names = ["AGAVO", "LAMEN", "ANDOL", "APELA", "ATOTI", "BESNA", "IGRAS", "INVOK", "KALEK", "KANSU", "LANAT", "MESOV", "MUGUS", "ONIKU", "RUGMA", "SAMDO", "SAPRA", "BEDAR", "GOLOT", "TOMUK", "VASRO", "ADNUR", "RIVAT"];

function convertToDecimal(str) {
    function MinutesToDecimal(d, m, s) {
        y = parseFloat(d) + parseFloat(m) / 60 + parseFloat(s) / 3600;
        return y;
    }

    var prefix = str[0];

    str = str.substr(1);

    var tokens = str.split(".");

    var ret = MinutesToDecimal(tokens[0], tokens[1], +(tokens[2] + "." + tokens[3]));
    if (prefix == 'S' || prefix == 'W')
        ret = -ret;

    return ret;
}

async function generate() {
    const navaid_raw = await fetch(`https://raw.githubusercontent.com/lancard/korea-flight-database/refs/heads/master/database/navaid.json`);
    const navaid = await navaid_raw.json();
    const mapped_navaids = navaid.map(navaid => {
        return {
            name: navaid.name,
            navaidType: navaid.navaidType,
            latitude: convertToDecimal(navaid.latitude),
            longitude: convertToDecimal(navaid.longitude)
        };
    });

    const boundary_navaids = mapped_navaids.filter(navaid => boundary_fix_names.includes(navaid.name));
    // map to convert lat and lon to decimal

    // print fir boundary fix list
    console.log(
`#define NUMBER_OF_FIR_BOUNDARY_FIX_LIST ${boundary_navaids.length}
CPosition fir_boundary_fix_list[NUMBER_OF_FIR_BOUNDARY_FIX_LIST];
${boundary_navaids.map(navaid => `CPosition *${navaid.name};`).join("\n")}

void InitializeFirBoundaryFixes() {
    ${boundary_navaids.map((navaid, index) => {
        return `${navaid.name} = &fir_boundary_fix_list[${index}];
    fir_boundary_fix_list[${index}].m_Latitude = ${navaid.latitude};
    fir_boundary_fix_list[${index}].m_Longitude = ${navaid.longitude};`;
    }).join("\n\n    ")}
}
`
    );

    const general_navaids = mapped_navaids.filter(navaid => navaid.navaidType === "FIX" && !boundary_fix_names.includes(navaid.name));

    // print general fix list
    console.log(
`#define NUMBER_OF_FIX_LIST ${general_navaids.length}
CPosition fix_list[NUMBER_OF_FIX_LIST];
${general_navaids.map(navaid => `CPosition *${navaid.name};`).join("\n")}

void InitializeFixes() {
    ${general_navaids.map((navaid, index) => {
        return `${navaid.name} = &fix_list[${index}];
    fix_list[${index}].m_Latitude = ${navaid.latitude};
    fix_list[${index}].m_Longitude = ${navaid.longitude};`;
    }).join("\n\n    ")}
}
`
    );
}

generate();