
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>HR Claims Portal</title>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.6.0/css/all.min.css">
    <script src="https://cdn.jsdelivr.net/npm/chart.js@4.4.2/dist/chart.umd.min.js"></script>
    <style>
        :root {
            --primary-blue: #1e1ed8;
            --dark-blue: #3329b9;
            --light-blue: #e6f2ff;
            --purple: #9436b9;
            --dark-purple: #7a0ca9;
            --green: #51d688;
            --dark-green: #27ae60;
            --red: #e74c3c;
            --dark-red: #c0392b;
            --gray: #e7fbff;
            --dark-gray: #474747;
            --orange: #ff9d00;
            --cyan: #cf0075;
            --pink: #00ab58;
        }

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
        }

        body {
            background-color: rgb(255, 255, 255);
            color: #333;
        }

        .container {
            max-width: 1200px;
            margin: 0 auto;
            padding: 20px;
        }

        header {
            position: relative;
            text-align: center;
            height: 140px;
background: linear-gradient(rgb(10, 10, 255),rgb(203, 11, 242));
            color: #fff;
            border-radius: 15px;
            overflow: hidden;
            display: flex;
            width: 100%;
            align-items: center;
            justify-content: center;
            flex-direction: column;
            box-shadow: 0 10px 30px rgba(0, 0, 0, 0.1);
            margin-bottom: 30px;
        }

        header h1 {
            margin: 0;
            font-size: 2.5rem;
            color: white;
            font-weight: 700;
            letter-spacing: 1px;
            position: relative;
            z-index: 2;
            text-shadow: 0 2px 4px rgba(0, 0, 0, 0.2);
        }

        header p {
            font-weight: 300;
            font-size: 1.1rem;
            margin-top: 10px;
            opacity: 0.9;
        }

        @keyframes moveCircles {
            0% { transform: translateY(0) translateX(0); }
            50% { transform: translateY(-50%) translateX(-50%); }
            100% { transform: translateY(0) translateX(0); }
        }

        .banner-background {
            position: absolute;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            z-index: 1;
            overflow: hidden;
        }

        .circle {
            position: absolute;
            width: 200px;
            height: 200px;
            background: rgba(255, 255, 255, 0.1);
            border-radius: 50%;
            animation: moveCircles 15s infinite linear;
        }

        .circle:nth-child(1) {
            top: 10%;
            left: 20%;
            animation-duration: 15s;
        }

        .circle:nth-child(2) {
            top: 50%;
            left: 70%;
            animation-duration: 20s;
            animation-direction: reverse;
        }

        .circle:nth-child(3) {
            top: 80%;
            left: 40%;
            animation-duration: 25s;
        }
        .nav-tabs {
            display: flex;
            justify-content: center;
            margin-bottom: 20px;
        }

        .nav-tab {
            padding: 10px 20px;
            cursor: pointer;
            font-size: 1.1rem;
            font-weight: 500;
            color: var(--dark-blue);
            background-color: var(--gray);
            margin: 0 5px;
            border-radius: 6px;
            transition: all 0.3s;
        }

        .nav-tab.active {
            background: linear-gradient(135deg, var(--primary-blue), var(--purple));
            color: white;
        }

        .nav-tab:hover {
            background: linear-gradient(135deg, var(--dark-blue), var(--dark-purple));
            color: white;
        }

        .section-title {
            font-size: 1.8rem;
            margin: 30px 0 20px;
            color: var(--dark-blue);
            position: relative;
            padding-bottom: 10px;
        }

        .section-title::after {
            content: '';
            position: absolute;
            bottom: 0;
            left: 0;
            width: 100px;
            height: 4px;
            background: linear-gradient(90deg, var(--primary-blue), var(--purple));
            border-radius: 2px;
        }

        .section {
            display: none;
            width: 100%;
        }

        .section.active {
            display: block;
        }

        .claims-table {
            width: 100%;
            border-collapse: collapse;
            margin-top: 20px;
            background: white;
            border-radius: 10px;
            box-shadow: 0 5px 20px rgba(0, 0, 0, 0.08);
            border: 1px solid var(--gray);
        }

        .claims-table th {
            background: linear-gradient(135deg, var(--primary-blue), var(--purple));
            color: white;
            padding: 12px 15px;
            text-align: left;
        }

        .claims-table td {
            padding: 12px 15px;
            border-bottom: 1px solid var(--gray);
        }

        .claims-table tr:nth-child(even) {
            background-color: #f9f9f9;
        }

        .claims-table tr:hover {
            background-color: var(--light-blue);
        }

        .no-claims {
            text-align: center;
            padding: 40px;
            color: #777;
        }

        .btn {
            padding: 8px 15px;
            border: none;
            border-radius: 6px;
            font-size: 0.9rem;
            font-weight: 500;
            cursor: pointer;
            transition: all 0.3s;
            display: inline-flex;
            align-items: center;
            gap: 8px;
        }

        .btn-approve {
            background: linear-gradient(135deg, var(--green), var(--dark-green));
            color: white;
        }

        .btn-approve:hover {
            background: linear-gradient(135deg, var(--dark-green), #219653);
        }

        .btn-reject {
            background: linear-gradient(135deg, var(--red), var(--dark-red));
            color: white;
        }

        .btn-reject:hover {
            background: linear-gradient(135deg, var(--dark-red), #a93226);
        }

        .btn-details {
            background: linear-gradient(135deg, var(--primary-blue), var(--purple));
            color: white;
        }

        .btn-details:hover {
            background: linear-gradient(135deg, var(--dark-blue), var(--dark-purple));
        }

        .status {
            padding: 5px 10px;
            border-radius: 20px;
            font-size: 0.8rem;
            font-weight: 500;
        }

        .status-pending {
            background-color: var(--orange);
            color: white;
        }

        .status-approved {
            background-color: var(--green);
            color: white;
        }

        .status-rejected {
            background-color: var(--red);
            color: white;
        }

.modal {
    display: none;
    position: fixed;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background-color: rgba(0, 0, 0, 0.7);
    justify-content: center;
    align-items: center;
    z-index: 1000;
    backdrop-filter: blur(5px);
    animation: fadeIn 0.3s ease-out;
}

.modal-content {
    background: white;
    border-radius: 12px;
    padding: 25px;
    width: 90%;
    max-width: 500px; /* Reduced max-width for better single column layout */
    max-height: 85vh;
    overflow-y: auto;
    box-shadow: 0 10px 30px rgba(0, 0, 0, 0.2);
    border: 1px solid rgba(255, 255, 255, 0.2);
    transform: translateY(0);
    transition: all 0.3s ease;
    position: relative;
}
.modal-content:hover {
    box-shadow: 0 15px 35px rgba(0, 0, 0, 0.25);
}

.modal-header {
    font-size: 1.8rem;
    font-weight: 600;
    margin-bottom: 20px;
    color: var(--dark-blue);
    display: flex;
    justify-content: space-between;
    align-items: center;
    padding-bottom: 15px;
    border-bottom: 1px solid rgba(0, 0, 0, 0.1);
}
.modal-header i {
    font-size: 1.5rem;
    color: var(--dark-gray);
    transition: all 0.2s;
    padding: 5px;
    border-radius: 50%;
}
.modal-header i:hover {
    color: var(--red);
    background-color: rgba(231, 76, 60, 0.1);
    transform: rotate(90deg);
}
.modal-body {
    margin-bottom: 20px;
}

/* Single column layout */
.modal-details {
    display: flex;
    flex-direction: column;
    gap: 15px;
}
.modal-details .detail-row {
    display: flex;
    flex-direction: column;
    padding-bottom: 15px;
    border-bottom: 1px solid rgba(0, 0, 0, 0.05);
}
.modal-details .detail-row:last-child {
    border-bottom: none;
}
.modal-details .detail-label {
    font-weight: 600;
    color: var(--dark-blue);
    margin-bottom: 5px;
    font-size: 0.95rem;
}

.modal-details p {
    margin: 0;
    font-size: 1rem;
    word-break: break-word;
    line-height: 1.5;
    color: #555;
}


.modal-details a {
    color: var(--primary-blue);
    text-decoration: none;
    display: inline-flex;
    align-items: center;
    gap: 8px;
    transition: all 0.2s;
    padding: 5px 0;
}

.modal-details a:hover {
    color: var(--dark-blue);
    text-decoration: underline;
}
.modal-details a i {
    font-size: 1.1rem;
}


.modal-actions {
    display: flex;
    justify-content: flex-end;
    gap: 15px;
    margin-top: 25px;
    padding-top: 15px;
    border-top: 1px solid rgba(0, 0, 0, 0.1);
}

        .btn-secondary {
            background: linear-gradient(135deg, var(--dark-gray), #95a5a6);
            color: white;
        }

        .btn-secondary:hover {
            background: linear-gradient(135deg, #95a5a6, #7f8c8d);
        }

        .success-message {
            display: none;
            background: linear-gradient(135deg, var(--green), var(--dark-green));
            color: white;
            padding: 20px;
            border-radius: 8px;
            margin-bottom: 30px;
            text-align: center;
            animation: fadeIn 0.5s ease-out;
        }

        .success-message.show {
            display: block;
        }

        .success-icon {
            font-size: 3rem;
            margin-bottom: 15px;
            animation: bounce 1s;
        }

        .claims-stats {
            display: flex;
            justify-content: space-between;
            align-items: flex-start;
            margin-top: 20px;
            gap: 20px;
        }

        .totals {
            flex: 1;
            background: white;
            padding: 15px;
            height: 300px;
            border-radius: 8px;
            box-shadow: 0 3px 10px rgba(0, 0, 0, 0.08);
        }

        .totals h3 {
            font-size: 1.2rem;
            color: var(--dark-blue);
            margin-bottom: 10px;
        }

        .totals p {
            font-size: 1rem;
            margin: 5px 0;
        }

        .graph-container {
            flex: 1;
            max-width: 500px;
            background: white;
            padding: 15px;
            border-radius: 8px;
            box-shadow: 0 3px 10px rgba(0, 0, 0, 0.08);
            height: 300px;
        }

        .graph-container canvas {
            max-height: 250px;
        }

        .truncate {
            white-space: nowrap;
            overflow: hidden;
            text-overflow: ellipsis;
            max-width: 150px;
            display: inline-block;
        }

        @media (max-width: 768px) {
            .claims-stats {
                flex-direction: column;
            }
            .graph-container {
                max-width: 100%;
                height: 300px;
            }
            .modal-details {
                grid-template-columns: 1fr;
            }
            .modal-details .detail-label {
                margin-top: 10px;
            }
        }

        @keyframes fadeIn {
            from { opacity: 0; }
            to { opacity: 1; }
        }

        @keyframes bounce {
            0%, 20%, 50%, 80%, 100% { transform: translateY(0); }
            40% { transform: translateY(-20px); }
            60% { transform: translateY(-10px); }
        }
        /* Animation for modal entry */
@keyframes modalSlideIn {
    from {
        opacity: 0;
        transform: translateY(-50px);
    }
    to {
        opacity: 1;
        transform: translateY(0);
    }
}

.modal-content {
    animation: modalSlideIn 0.4s cubic-bezier(0.175, 0.885, 0.32, 1.275);
}

/* Custom scrollbar for modal */
.modal-content::-webkit-scrollbar {
    width: 8px;
}

.modal-content::-webkit-scrollbar-track {
    background: rgba(0, 0, 0, 0.05);
    border-radius: 10px;
}

.modal-content::-webkit-scrollbar-thumb {
    background: var(--primary-blue);
    border-radius: 10px;
}

.modal-content::-webkit-scrollbar-thumb:hover {
    background: var(--dark-blue);
}

/* Responsive adjustments */
@media (max-width: 600px) {
    .modal-content {
        width: 95%;
        padding: 20px 15px;
    }
    
    .modal-header {
        font-size: 1.5rem;
    }
    
    .modal-actions {
        justify-content: center;
        flex-wrap: wrap;
    }
    
    .modal-actions .btn {
        flex: 1;
        min-width: 120px;
        text-align: center;
    }
}

    </style>
</head>
<body>
    <div class="container">
        <header>
                 <div class="banner-background">
                <div class="circle"></div>
                <div class="circle"></div>
                <div class="circle"></div>
            </div>
            <h1>HR Claims Portal</h1>
            <p>Manage employee reimbursement claims</p>
        </header>
        <div class="nav-tabs">
            <div class="nav-tab active" onclick="showSection('action-required')">Action Required</div>
            <div class="nav-tab" onclick="showSection('action-completed')">Action Completed</div>
        </div>

        <div class="success-message" id="successMessage">
            <div class="success-icon"><i class="fas fa-check-circle"></i></div>
            <h3>Action Completed Successfully!</h3>
            <p>The claim has been updated. Review other pending claims or check completed actions.</p>
        </div>

        <section id="action-required" class="section active">
            <h2 class="section-title">Pending Claims</h2>
            <div class="claims-stats">
                <div class="totals" id="pendingTotals">
                    <h3>Pending Claims Summary</h3>
                    <p><strong>Total Amount:</strong> ₹0</p>
                </div>
                <div class="graph-container">
                    <canvas id="pendingChart"></canvas>
                </div>
            </div>
            <table class="claims-table" id="pendingTable">
                <thead>
                    <tr>
                        <th>Claim ID</th>
                        <th>Type</th>
                        <th>Employee ID</th>
                        <th>Employee Name</th>
                        <th>Amount</th>
                        <th>Status</th>
                        <th>Actions</th>
                    </tr>
                </thead>
                <tbody></tbody>
            </table>
            <div class="no-claims" id="noPendingClaims" style="display: none;">
                <i class="fas fa-folder-open" style="font-size: 3rem; color: #ccc; margin-bottom: 15px;"></i>
                <h3>No Pending Claims</h3>
                <p>All claims have been processed or no claims are pending review.</p>
            </div>
        </section>

        <section id="action-completed" class="section">
            <h2 class="section-title">Completed Claims</h2>
            <div class="claims-stats">
                <div class="totals" id="completedTotals">
                    <h3>Completed Claims Summary</h3>
                    <p><strong>Total Amount:</strong> ₹0</p>
                </div>
                <div class="graph-container">
                    <canvas id="completedChart"></canvas>
                </div>
            </div>
            <table class="claims-table" id="completedTable">
                <thead>
                    <tr>
                        <th>Claim ID</th>
                        <th>Type</th>
                        <th>Employee ID</th>
                        <th>Employee Name</th>
                        <th>Amount</th>
                        <th>Status</th>
                        <th>Actions</th>
                    </tr>
                </thead>
                <tbody></tbody>
            </table>
            <div class="no-claims" id="noCompletedClaims" style="display: none;">
                <i class="fas fa-folder-open" style="font-size: 3rem; color: #ccc; margin-bottom: 15px;"></i>
                <h3>No Completed Claims</h3>
                <p>No claims have been approved or rejected yet.</p>
            </div>
        </section>

        <div class="modal" id="detailsModal">
            <div class="modal-content">
                <div class="modal-header">
                    <span>Claim Details</span>
                    <i class="fas fa-times" style="cursor: pointer;" onclick="closeModal('detailsModal')"></i>
                </div>
                <div class="modal-body">
                    <div class="modal-details" id="claimDetails"></div>
                </div>
                <!-- <div class="modal-actions">
                    <button class="btn btn-secondary" onclick="closeModal('detailsModal')">
                        <i class="fas fa-times"></i> Close
                    </button>
                </div> -->
            </div>
        </div>
    </div>

    <script>
        let pendingChartInstance = null;
        let completedChartInstance = null;
        const CLAIM_TYPES = ['Medical', 'Travel', 'Education', 'Meal', 'Equipment', 'Other'];
        const TYPE_COLORS = {
            'Medical': 'rgba(0, 123, 255, 0.6)',
            'Travel': 'rgba(40, 167, 69, 0.6)',
            'Education': 'rgba(102, 16, 242, 0.6)',
            'Meal': 'rgba(255, 193, 7, 0.6)',
            'Equipment': 'rgba(23, 162, 184, 0.6)',
            'Other': 'rgba(220, 53, 69, 0.6)'
        };
        const TYPE_BORDER_COLORS = {
            'Medical': 'rgba(0, 123, 255, 1)',
            'Travel': 'rgba(40, 167, 69, 1)',
            'Education': 'rgba(102, 16, 242, 1)',
            'Meal': 'rgba(255, 193, 7, 1)',
            'Equipment': 'rgba(23, 162, 184, 1)',
            'Other': 'rgba(220, 53, 69, 1)'
        };

        function showSection(sectionId) {
            document.querySelectorAll('.section').forEach(section => section.classList.remove('active'));
            document.querySelectorAll('.nav-tab').forEach(tab => tab.classList.remove('active'));
            document.getElementById(sectionId).classList.add('active');
            document.querySelector(`.nav-tab[onclick="showSection('${sectionId}')"]`).classList.add('active');
            document.getElementById('successMessage').classList.remove('show');
            document.getElementById(sectionId).scrollIntoView({ behavior: 'smooth' });
            updateTables();
        }

        function closeModal(modalId) {
            document.getElementById(modalId).style.display = 'none';
        }

        function renderChart(canvasId, chartInstanceRef, labels, data, backgroundColors, borderColors) {
            const ctx = document.getElementById(canvasId).getContext('2d');
            if (chartInstanceRef) {
                chartInstanceRef.destroy();
            }
            chartInstanceRef = new Chart(ctx, {
                type: 'bar',
                data: {
                    labels: labels,
                    datasets: [{
                        label: 'Claim Amount (₹)',
                        data: data,
                        backgroundColor: backgroundColors,
                        borderColor: borderColors,
                        borderWidth: 1
                    }]
                },
                options: {
                    responsive: true,
                    maintainAspectRatio: false,
                    scales: {
                        y: {
                            beginAtZero: true,
                            title: {
                                display: true,
                                text: 'Amount (₹)'
                            },
                            ticks: {
                                callback: function(value) {
                                    return '₹' + value.toLocaleString('en-IN');
                                }
                            }
                        },
                        x: {
                            title: {
                                display: true,
                                text: 'Claim Type'
                            }
                        }
                    },
                    plugins: {
                        legend: {
                            display: false
                        }
                    }
                }
            });
            return chartInstanceRef;
        }

        async function updateTables() {
            try {
                const response = await fetch('http://44.223.23.145:3407/api/claims');
                const claims = await response.json();

                const pendingTableBody = document.querySelector('#pendingTable tbody');
                const completedTableBody = document.querySelector('#completedTable tbody');
                const noPendingClaims = document.getElementById('noPendingClaims');
                const noCompletedClaims = document.getElementById('noCompletedClaims');
                const pendingTotals = document.getElementById('pendingTotals');
                const completedTotals = document.getElementById('completedTotals');

                pendingTableBody.innerHTML = '';
                completedTableBody.innerHTML = '';

                const pendingClaims = claims.filter(claim => claim.status === 'pending');
                const completedClaims = claims.filter(claim => ['approved', 'rejected'].includes(claim.status));

                // Pending Claims
                const typeTotalsPending = CLAIM_TYPES.reduce((acc, type) => {
                    acc[type] = 0;
                    return acc;
                }, {});
                pendingClaims.forEach(claim => {
                    if (CLAIM_TYPES.includes(claim.type)) {
                        typeTotalsPending[claim.type] += Math.floor(claim.amount);
                    } else {
                        typeTotalsPending['Other'] += Math.floor(claim.amount);
                    }
                });

                if (pendingClaims.length === 0) {
                    noPendingClaims.style.display = 'block';
                    pendingTotals.innerHTML = `
                        <h3>Pending Claims Summary</h3>
                        <p><strong>Total Amount:</strong> ₹0</p>
                        ${CLAIM_TYPES.map(type => `<p><strong>${type}:</strong> ₹0</p>`).join('')}
                    `;
                } else {
                    noPendingClaims.style.display = 'none';
                    const totalPending = Object.values(typeTotalsPending).reduce((sum, amount) => sum + amount, 0);
                    pendingTotals.innerHTML = `
                        <h3>Pending Claims Summary</h3>
                        <p><strong>Total Amount:</strong> ₹${totalPending.toLocaleString('en-IN')}</p>
                        ${CLAIM_TYPES.map(type => `<p><strong>${type}:</strong> ₹${typeTotalsPending[type].toLocaleString('en-IN')}</p>`).join('')}
                    `;
                    pendingClaims.forEach(claim => {
                        const row = document.createElement('tr');
                        row.innerHTML = `
                            <td>${claim.claim_id}</td>
                            <td>${claim.type}</td>
                            <td>${claim.employee_id}</td>
                            <td><span class="truncate" title="${claim.employee_name}">${claim.employee_name}</span></td>
                            <td>₹${Math.floor(claim.amount).toLocaleString('en-IN')}</td>
                            <td><span class="status status-${claim.status}">${claim.status.charAt(0).toUpperCase() + claim.status.slice(1)}</span></td>
                            <td>
                                <button class="btn btn-approve" onclick="updateClaimStatus('${claim.claim_id}', 'approved')">
                                    <i class="fas fa-check"></i> Approve
                                </button>
                                <button class="btn btn-reject" onclick="updateClaimStatus('${claim.claim_id}', 'rejected')">
                                    <i class="fas fa-times"></i> Reject
                                </button>
                                <button class="btn btn-details" onclick="viewClaim('${claim.claim_id}')">
                                    <i class="fas fa-eye"></i> Details
                                </button>
                            </td>
                        `;
                        pendingTableBody.appendChild(row);
                    });
                }
                pendingChartInstance = renderChart(
                    'pendingChart',
                    pendingChartInstance,
                    CLAIM_TYPES,
                    CLAIM_TYPES.map(type => typeTotalsPending[type]),
                    CLAIM_TYPES.map(type => TYPE_COLORS[type]),
                    CLAIM_TYPES.map(type => TYPE_BORDER_COLORS[type])
                );

                // Completed Claims
                const typeTotalsCompleted = CLAIM_TYPES.reduce((acc, type) => {
                    acc[type] = 0;
                    return acc;
                }, {});
                completedClaims.forEach(claim => {
                    if (CLAIM_TYPES.includes(claim.type)) {
                        typeTotalsCompleted[claim.type] += Math.floor(claim.amount);
                    } else {
                        typeTotalsCompleted['Other'] += Math.floor(claim.amount);
                    }
                });

                if (completedClaims.length === 0) {
                    noCompletedClaims.style.display = 'block';
                    completedTotals.innerHTML = `
                        <h3>Completed Claims Summary</h3>
                        <p><strong>Total Amount:</strong> ₹0</p>
                        ${CLAIM_TYPES.map(type => `<p><strong>${type}:</strong> ₹0</p>`).join('')}
                    `;
                } else {
                    noCompletedClaims.style.display = 'none';
                    const totalCompleted = Object.values(typeTotalsCompleted).reduce((sum, amount) => sum + amount, 0);
                    completedTotals.innerHTML = `
                        <h3>Completed Claims Summary</h3>
                        <p><strong>Total Amount:</strong> ₹${totalCompleted.toLocaleString('en-IN')}</p>
                        ${CLAIM_TYPES.map(type => `<p><strong>${type}:</strong> ₹${typeTotalsCompleted[type].toLocaleString('en-IN')}</p>`).join('')}
                    `;
                    completedClaims.forEach(claim => {
                        const row = document.createElement('tr');
                        row.innerHTML = `
                            <td>${claim.claim_id}</td>
                            <td>${claim.type}</td>
                            <td>${claim.employee_id}</td>
                            <td><span class="truncate" title="${claim.employee_name}">${claim.employee_name}</span></td>
                            <td>₹${Math.floor(claim.amount).toLocaleString('en-IN')}</td>
                            <td><span class="status status-${claim.status}">${claim.status.charAt(0).toUpperCase() + claim.status.slice(1)}</span></td>
                            <td>
                                <button class="btn btn-details" onclick="viewClaim('${claim.claim_id}')">
                                    <i class="fas fa-eye"></i> Details
                                </button>
                            </td>
                        `;
                        completedTableBody.appendChild(row);
                    });
                }
                completedChartInstance = renderChart(
                    'completedChart',
                    completedChartInstance,
                    CLAIM_TYPES,
                    CLAIM_TYPES.map(type => typeTotalsCompleted[type]),
                    CLAIM_TYPES.map(type => TYPE_COLORS[type]),
                    CLAIM_TYPES.map(type => TYPE_BORDER_COLORS[type])
                );
            } catch (error) {
                console.error('Error fetching claims:', error);
                alert('Error fetching claims: ' + error.message);
            }
        }

        async function updateClaimStatus(claimId, status) {
            const action = status.charAt(0).toUpperCase() + status.slice(1);
            const confirmed = window.confirm(`Are you sure you want to ${action.toLowerCase()} claim ${claimId}?`);
            if (!confirmed) return;

            try {
                const response = await fetch(`http://44.223.23.145:3407/api/claims/${claimId}`, {
                    method: 'PATCH',
                    headers: {
                        'Content-Type': 'application/json',
                    },
                    body: JSON.stringify({ status })
                });

                if (!response.ok) {
                    const error = await response.json();
                    throw new Error(error.error || 'Failed to update claim');
                }

                document.getElementById('successMessage').classList.add('show');
                document.getElementById('successMessage').scrollIntoView({ behavior: 'smooth' });
                await updateTables();
            } catch (error) {
                console.error('Error updating claim:', error);
                alert('Error updating claim: ' + error.message);
            }
        }

        async function viewClaim(claimId) {
            try {
                const [claimResponse, documentsResponse] = await Promise.all([
                    fetch(`http://44.223.23.145:3407/api/claims?claim_id=${claimId}`),
                    fetch(`http://44.223.23.145:3407/api/claims/${claimId}/documents`)
                ]);

                const claims = await claimResponse.json();
                const documents = await documentsResponse.json();

                const claim = claims[0];
                if (!claim) {
                    throw new Error('Claim not found');
                }

                const detailsDiv = document.getElementById('claimDetails');
detailsDiv.innerHTML = `
    <div class="detail-row">
        <p class="detail-label">Claim ID: <span style="color: black;">${claim.claim_id}</span></p>
    </div>
    <div class="detail-row">
        <p class="detail-label">Type: <span style="color: black;">${claim.type}</span></p>
    </div>
    <div class="detail-row">
        <p class="detail-label">Employee: 
            <span style="color: black;" title="${claim.employee_name}">${claim.employee_name.length > 30 ? 
                claim.employee_name.substring(0, 30) + '...' : claim.employee_name}</span>
        </p>
    </div>
    <div class="detail-row">
        <p class="detail-label">Email: <span style="color: black;">${claim.employee_email}</span></p>
    </div>
    <div class="detail-row">
        <p class="detail-label">Employee ID: <span style="color: black;">${claim.employee_id}</span></p>
    </div>
    <div class="detail-row">
        <p class="detail-label">Department: <span style="color: black;">${claim.department}</span></p>
    </div>
    <div class="detail-row">
        <p class="detail-label">Date: <span style="color: black;">${new Date(claim.claim_date).toLocaleDateString()}</span></p>
    </div>
    <div class="detail-row">
        <p class="detail-label">Amount: <span style="color: black;">₹${Math.floor(claim.amount).toLocaleString('en-IN')}</span></p>
    </div>
    <div class="detail-row">
        <p class="detail-label">Description: <span style="color: black;">${claim.description}</span></p>
    </div>
    <div class="detail-row">
        <p class="detail-label">Status: <span style="color: black;">${claim.status.charAt(0).toUpperCase() + claim.status.slice(1)}</span></p>
    </div>
    <div class="detail-row">
        <p class="detail-label">Documents:</p>
        <div style="margin-left: 15px; color: black;">
            ${documents.length > 0 ? 
                documents.map(doc => `
                    <p>
                        <a href="javascript:void(0)" onclick="downloadDocument('${doc.id}', '${doc.file_name}')">
                            <i class="fas fa-file-download"></i> ${doc.file_name}
                        </a>
                    </p>
                `).join('') : 
                '<p>No documents uploaded</p>'}
        </div>
    </div>
`;


                document.getElementById('detailsModal').style.display = 'flex';
            } catch (error) {
                console.error('Error viewing claim:', error);
                alert('Error viewing claim: ' + error.message);
            }
        }

        async function downloadDocument(documentId, fileName) {
            try {
                // First get the file path from the server
                const response = await fetch(`http://44.223.23.145:3407/api/documents/${documentId}`);
                
                if (!response.ok) {
                    throw new Error('Failed to download document');
                }

                // Create a temporary anchor element to trigger the download
                const url = `http://44.223.23.145:3407/api/documents/${documentId}`;
                const a = document.createElement('a');
                a.href = url;
                a.download = fileName;
                document.body.appendChild(a);
                a.click();
                document.body.removeChild(a);
                
                // Revoke the object URL to free up memory
                setTimeout(() => {
                    window.URL.revokeObjectURL(url);
                }, 100);
            } catch (error) {
                console.error('Error downloading document:', error);
                alert('Error downloading document: ' + error.message);
            }
        }

        document.addEventListener('DOMContentLoaded', function() {
            showSection('action-required');
            updateTables();
        });
    </script>
</body>
</html>

