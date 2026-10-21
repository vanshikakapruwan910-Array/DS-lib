
import streamlit as st
from collections import deque

st.set_page_config(
    page_title="DSLib",
    page_icon="🏥",
    layout="wide"
)

st.title("DSLib : Domain-Specific Data Structures")
st.caption("A C++ data structures library for real-world workflows")

# Keep demo data between Streamlit reruns
if "items" not in st.session_state:
    st.session_state.items = []

if "history" not in st.session_state:
    st.session_state.history = []


domain = st.sidebar.selectbox(
    "Choose domain",
    ["Regular", "Hospital", "School", "Bank"]
)

structure = st.sidebar.selectbox(
    "Choose data structure",
    ["Queue", "Deque", "Stack", "Linked List", "Tree", "Graph"]
)

st.header(f"{domain} | {structure}")


if structure == "Queue":
    st.subheader("Queue Operations")

    with st.form("add_item"):
        item_id = st.text_input("Record ID")
        item_name = st.text_input("Name")
        submitted = st.form_submit_button("Add to Queue")

    if submitted:
        if item_id.strip() and item_name.strip():
            if any(
                item["id"] == item_id.strip()
                for item in st.session_state.items
            ):
                st.error("This ID already exists.")
            else:
                st.session_state.items.append({
                    "id": item_id.strip(),
                    "name": item_name.strip()
                })
                st.session_state.history.append(
                    f"Added {item_id.strip()}"
                )
                st.success("Record added successfully.")
        else:
            st.warning("Enter both an ID and a name.")

    col1, col2 = st.columns(2)

    with col1:
        if st.button("Serve Next", use_container_width=True):
            if st.session_state.items:
                removed = st.session_state.items.pop(0)
                st.session_state.history.append(
                    f"Served {removed['id']}"
                )
                st.success(f"Served: {removed['name']}")
            else:
                st.warning("The queue is empty.")

    with col2:
        if st.button("Clear Demo Data", use_container_width=True):
            st.session_state.items = []
            st.session_state.history = []
            st.rerun()

#add from sample.txt here

